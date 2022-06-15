import java.util.ArrayList;

public class Player extends Observer {

	int idx;
	ArrayList<Playable> list;
	
	
	public Player() {
		idx = -1;
		list = new ArrayList<>();
	}
	
	public void show_list() {
		System.out.println("Player list: ");
		for(Playable p: list) {
			if(p instanceof Audio)
				((Audio) p).info();
			
			if(p instanceof Video)
				((Video) p).info();
		}
	}
	
	public void refresh() {
		Playable temp = null;
		if(idx > -1 && idx < list.size())
			temp = list.get(idx);
		
		list.clear();	
		for(int i = 0;i<d.contents.size();i++) {
			if(d.contents.get(i) instanceof Playable) {
				if(temp == null) {
					temp = (Playable) d.contents.get(i);
					idx = list.size();
				}
				
				if((Playable) d.contents.get(i) == temp) {
					idx = list.size();
				}
				list.add((Playable) d.contents.get(i));
			}
		}
	}
	
	public void next(){
		if(idx < list.size())
			idx++;
	}
	
	public void prev(){
		if(idx > -1)
			idx--;
	}
	
	public Playable currently_playing() {
		if(idx == list.size() || idx < 0) {
			System.out.println("List size is exceeded!");  // error print
			return null;
		}
		return list.get(idx);
	}
}
