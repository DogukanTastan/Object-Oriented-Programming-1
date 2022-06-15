public class Audio extends Content implements Non_visual, Playable{
	String duration;
	public Audio(String name, String duration, String other_info) {
		super(name, other_info);  // Necessary information is sent to the base class
		this.duration = duration;
	}
	
	@Override
	public void info() {	// info info is overridden as it will be in every inherited class
		System.out.println("Name: " + name + ", Duration: " + duration + ", Other info: " + other_info);
	}
}