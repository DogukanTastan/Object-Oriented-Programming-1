public class Main {			// Dogukan Tastan 1901042627
	
	public static void main(String [] args) {
		//This is our data set. We have only one data set.
		Dataset ds = new Dataset();

		//Lets create different observers.
		Player p1 = new Player();
		Player p2 = new Player();
		Viewer v1 = new Viewer();
		Viewer v2 = new Viewer();
		
		//Lets register them to our data set so that they can reach to data and updates.
		//You can also register them to the data set when you create them.
	
		// ds has to figure out the type of the observer.
		// it should not send unrelated information.
		// For example, viewer objects don't want to know anything about playable objects.
		ds.register(p1);
		ds.register(p2);
		ds.register(v1);
		ds.register(v2);
		
		ds.add(new Image("imagename1", "dimension info1", "other info1"));
		ds.add(new Image("imagename2", "dimension info2", "other info2"));
		ds.add(new Image("imagename3", "dimension info3", "other info3"));
		ds.add(new Image("imagename4", "dimension info4", "other info4"));
		ds.add(new Image("imagename5", "dimension info5", "other info5"));
		ds.add(new Audio("audioname1", "duration1", "other info1"));
		ds.add(new Audio("audioname2", "duration2", "other info2"));
		ds.add(new Audio("audioname3", "duration3", "other info3"));
		ds.add(new Video("videoname1", "duration1", "other info1"));
		ds.add(new Video("videoname2", "duration2", "other info2"));
		ds.add(new Video("videoname3", "duration3", "other info3"));
		ds.add(new Text("textname1", "other info1"));
		ds.add(new Text("textname2", "other info2"));
		ds.add(new Text("textname3", "other info3"));
		
		//Lets use one of the player objects.
		//We can get the currently playing object
		Playable po = p1.currently_playing();
		
		System.out.println("Prints first playable content of \"Player p1\"");
		po.info();
		
		System.out.println("\n");

		System.out.println("Iterating over \"Player p2\" with using next");
		Playable p = p2.currently_playing();
		while(p2.currently_playing() != null) {
			p = p2.currently_playing();
			p.info();
			p2.next();
		}
		
		System.out.println("\nDeleting current item of \"Player 1\"");
		//we can remove this object from the dataset
		ds.remove(po);
		
		System.out.println("Iterating over \"Player p2\" with using next()");
		p = p1.currently_playing();
		while(p1.currently_playing() != null) {
			p = p1.currently_playing();
			p.info();
			p1.next();
		}
		
		System.out.println("Iterating over \"Player p2\" with using prev()");
		p1.prev();
		while(p1.currently_playing() != null) {
			p = p1.currently_playing();
			p.info();
			p1.prev();
		}
		
		System.out.println("\n");
		
		//po is no longer in the dataset. all of the interested observers will get this update.
		//similarly, viewer object:
		
		System.out.println("Iterating over \"Viewer v1\" with using next()");
		Visual np = v1.currently_viewing();
		
		while(v1.currently_viewing() !=null) {
			np = v1.currently_viewing();
			np.info();
			v1.next();
		}
	}
}
