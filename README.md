# elevator_with_remote
Test from Fagskolen i Viken - programmering

/*Garasjeport av Asgeir Bjørgen Huskebakk
*
* Dette prosjektet inneholder:
	- DC motor
    - motorstyrer (L293D)
    - ledlys
    - lampe
    - strømforsyning
    - LCD display
    - 4 knapper
    - IR mottaker
    - fjernkontroll
    - 2 stk arduino
    - motstander
    - potensiometer
    
* Funksjon:
	- Garasjeporten starter åpen.
    - knapp opp (1 på fjernkontroll) kjører porten opp
    - knapp ned (2 på fjernkontroll) kjører porten ned
    - knapp lys (3 på fjernkontroll) gir lampe lys i variabel tid (40 sec)
    - knapp motstand fungerer som montstand når heisen går nedover
   		trykkes denne inn, stopper motor og går 0.2 meter oppover.
    - lampe lyser i 40 sec etter at motor et stoppet.
    - LCD printer portens status
    - led lyser mens motor går
    - Info kan også sees i seriell overvåker.
 
*/
