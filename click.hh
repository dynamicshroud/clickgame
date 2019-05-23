#ifndef CLICK_HH
#define CLICK_HH

struct Player {
	int total_clicks;
	int total_coins;
	int click_bonus;
	Player(){
		total_clicks = 0;
		total_coins = 0;
		click_bonus = 1;
	}
};

void click(Player&);
void updateMultiplier(Player&);

#endif
