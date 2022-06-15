
public class Text extends Content implements Non_visual, Non_playable{
	public Text(String name, String info) { // Necessary information is sent to the base class
		super(name, info);
	}
	
	@Override
	public void info() { // info info is overridden as it will be in every inherited class
		System.out.println("Name: " + name + ", Other info: " + other_info);
	}	
}
