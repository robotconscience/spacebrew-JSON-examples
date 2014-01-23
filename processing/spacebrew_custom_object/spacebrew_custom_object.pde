import spacebrew.*;

String server= "sandbox.spacebrew.cc";
String name="P5 Custom Example - Objects";
String description ="";

Spacebrew sb;

void setup(){
  size(800,600);
  sb = new Spacebrew( this );
  sb.addPublish ("p5Point", "point2d", "\"x\":0, \"y\":0");
  sb.addSubscribe ("p5Point", "point2d");
  sb.connect(server, name, description);
}

PVector localPoint = new PVector(0,0);
PVector remotePoint = new PVector(0,0);
JSONObject outgoing = new JSONObject();

void draw(){
  localPoint.set(mouseX, mouseY);
  background(50);
  fill(0);
  ellipse(localPoint.x, localPoint.y, 20,20);
  fill(255);
  ellipse(remotePoint.x, remotePoint.y, 20,20);
  
  outgoing.setInt("x", mouseX);
  outgoing.setInt("y", mouseY);
  
  sb.send("p5Point", "point2d", outgoing.toString());
}

void onCustomMessage( String name, String type, String value ){
  if ( type.equals("point2d") ){
    // parse JSON!
    JSONObject m = JSONObject.parse( value );
    remotePoint.set( m.getInt("x"), m.getInt("y"));
  }
}
