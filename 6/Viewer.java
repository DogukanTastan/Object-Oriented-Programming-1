import java.util.ArrayList;

public class Viewer extends Observer {

	int idx;
	ArrayList<Visual> list;
	
	
	public Viewer() {
		idx = -1;
		list = new ArrayList<>();
	}
	
	public void show_list() {
		System.out.println("Viewer list: ");
		for(Visual v: list) {		// we search the whole list
			if(v instanceof Image)
				((Image) v).info();
			
			if(v instanceof Video)
				((Video) v).info();
		}
	}
	
	public void refresh() {
		Visual temp = null;
		if(idx > -1)		// Checking the idx
			temp = list.get(idx);
		
		idx = -1;
		list.clear();
			
		for(int i = 0;i<d.contents.size();i++) {
			if(d.contents.get(i) instanceof Visual) {
				if(temp == null) {
					temp = (Visual) d.contents.get(i);
					idx = list.size();
				}
				
				if((Visual) d.contents.get(i) == temp) {
					idx = list.size();
				}
				list.add((Visual) d.contents.get(i));
			}
		}
	}
	
	public void next(){
		if(idx < list.size()) // control of list size
			idx++;
	}
	
	public void prev(){  // go back
		if(idx > -1)
			idx--;
	}
	
	public Visual currently_viewing() {
		if(idx == list.size() || idx < 0) {
			System.out.println("List size is exceeded!");  // error print 
			return null;
		}
		return list.get(idx);
	}
}
