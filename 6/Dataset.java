import java.util.ArrayList;

public class Dataset {
	ArrayList<Content> contents;
	ArrayList<Observer> observers;
	
	public Dataset() {
		contents = new ArrayList<>();  // lists to store objects
		observers = new ArrayList<>();
	}
	
	public void register(Observer o) {
		o.d = this;
		observers.add(o);
	}
	
	public void remove_observer(Observer o) {
		observers.remove(o);
	}
	
	public void add(Content c) {
		contents.add(c);
		if(c instanceof Audio || c instanceof Video) {
			for(Observer o: observers) {
				if(o instanceof Player)
					o.refresh();
			}
		}
		if(c instanceof Image || c instanceof Video) { // Necessary actions are taken by looking at the type of objects.
			for(Observer o: observers) {
				if(o instanceof Viewer)
					o.refresh();
			}
		}
	}
	
	public void remove(Object c) {
		contents.remove(c);
		if(c instanceof Audio || c instanceof Video) {
			for(Observer o: observers) {
				if(o instanceof Player)
					o.refresh();
			}
		}
		if(c instanceof Image || c instanceof Video) {
			for(Observer o: observers) {
				if(o instanceof Viewer)
					o.refresh();
			}
		}
	}
}