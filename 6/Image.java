public class Image extends Content implements Visual, Non_playable{
	String dimension;
	
	public Image(String name, String dimension, String other_info) {
		super(name, other_info); // Necessary information is sent to the base class
		this.dimension = dimension;
	}
	
	@Override
	public void info() { // info info is overridden as it will be in every inherited class
		System.out.println("Name: " + name + ", Other info: " + other_info);
	}
}