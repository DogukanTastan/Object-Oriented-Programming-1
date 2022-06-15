public abstract class Content { // This class is abstract because there is no content object.
	String name;
	String other_info;
	
	public Content(String name, String other_info) {
		this.name = name;
		this.other_info = other_info; //Necessary initial operations are done in the constructor function
	}
}
