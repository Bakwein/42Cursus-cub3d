#!/bin/bash
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

cat << "END" 
   ___                                _   _     
  / _ \                              | | | |    
 / /_\ \_ __ ___   ___  _ __   __ _  | | | |___ 
 |  _  | '_ ` _ \ / _ \| '_ \ / _` | | | | / __|
 | | | | | | | | | (_) | | | | (_| | | |_| \__ \
 \_| |_/_| |_| |_|\___/|_| |_|\__, |  \___/|___/
                               __/ |            
                              |___/             
END
make fclean
make bonus
echo ""
echo ""
echo -e "${BLUE}"
echo "You are a crewmate this turn"
echo "Find the dead body to win and go to the next round"
echo -e "${NC}"
./cub3D mapbonus_lvl0.cub
echo -e "${RED}"
echo -e "You are an Impostor this round, kill all the crewmates to win"
echo -e "Press Shift to Kill. 300 Frames cooldown."
echo -e "There is a 10% chance that doors will close when you kill."
echo -e "You can find secret passages in the map. Good Luck!"
echo -e "${NC}"
./cub3D mapbonus_the_skeld.cub
cat << "BY" 
   _____                 _ _           
  |  __ \               | | |          
  | |  \/ ___   ___   __| | |__  _   _ 
  | | __ / _ \ / _ \ / _` | '_ \| | | |
  | |_\ \ (_) | (_) | (_| | |_) | |_| |
   \____/\___/ \___/ \__,_|_.__/ \__, |
                                  __/ |
                                 |___/ 

Code and idea by bmerchin
Textures by vo-nguye
BY
