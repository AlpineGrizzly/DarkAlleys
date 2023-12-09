# Dark Alleys
## Bitcoin mining operation logistics indie style game 
### Idea
You start out having nothing but are in a city that has many abandoned buildings, you can set up camp in one and start stealing parts
from nearby stores to build computers and other gadgets to grow and scale your bitcoining mining operation. You can also using money generated
to buy upgrades opposed to stealing them. Parts will wear out. 

Enemies will consist of security guards who will check on warehouses if you don't lock the doors or leave windows open. Until you get AC units, windows can be opened
to cool down printers but this obvisouly opens it up for security guards to look in and report you. 

Their are also other bitcoin miners who will attempt to break into your warehouse to steal your parts. You use bitcoins to buy deterents like trip wires, dogs, and even construct underground
bunkers to store valuables like the server the host your bitcoin wallet. 

Able to hire computer programmers who can write malware such as ransomeware and trojans for bitcoin mining software to infect other miners computers to passively steal their bitcoin as well. Similiarly 
the player can be infected with malware and will have deter this by buying antivirus or ensuring that loitering enemies are trying to connect to your wifi to infect you. 

Their will be a mark for the price of a bitcoin that the player will be able to sell when it reaches a desired value. Otherwise they can hold on and wait for the market to buy at a higher price.

Able to tap into electrical grid for power but will draw suspiciion from police

Buy generators to power computers, must buy fuel, or can steal it but risk suspicion from the police

### BUGS

### TODO
- [ ] Figure out how to allow use of extended ascii characters
- [ ] Ensuring after map is generated, player is spawned in a building ina  random location?
- [ ] Using statitistics window, allow for monitoring of bitcoin miners and interacting buy coolant and whatnot
- [ ] Allow for selling of bitcoin with randomized day prices 
- [ ] Smart building generation would be cool, L shaped buildings and what not besides just rectangles
- [ ] Better door generation (Hardcoded to min+1 tile on y side for now)
- [ ] Create logging for debugging so i dont have to dive into gdb 
- [ ] Simple Inventory ( 5 items ) 
- [ ] Bitcoin minig logistics (Able to buy/steal a computer and set it up to mine bitcoin, can upgrade eventually)
- [ ] Shopkeep (Alternative option to finding or stealing
- [ ] Cop + enemy miner AI

### State
```sh
┌==================================================================================================┐
|@,. .. `.`.,,,`  ` ,.`   ,`` ., ```  .., `. `  ..`.`,.. .,.,.`  ,.`  ,,``.`.,.`. ,  .. `., `````,,|
|` ,`.   , ,`, `   ,``.`.,. `  `.`  ,`` `.,,.  .``.,,  . ,.. , . `, , ``,` ``` ,,,.. ,``,   , , ..`|
|`,,,,  `....``` .`.,`. `.``,, `` ``,.``` ,,.``, .`    .,.,,. `  ,` `,., .,.  . , ` `..` .`,,,, .``|
| `, ..,`. ,,  ```, , ,  .  ,,.     .,  .` .. , ., .  ,`,,`., ,,   , ` ., `.``, ` ,. ., .`,..,., ,,|
| `,,` ` ..,,  ,.`..`` `,, ..``..,.. ,,`..`.,``., ```..``,  `.,,``..`. ,``. , ,,   .,, `,`.`,```,, |
|`.``,,, ,  .``,  ,`.,. `... ..` `,``.`....`, ` ```,`  .,,` . .,..`,`,.,`````..,  ,``  ` ..,,`.., .|
|`, ``.., `.,..,  ,``   , `..`,`,,. ` ,```,` .  , .``.``,, .`,,`,.. ,..  .. `,`   .`, ,. ,`.,`,,,. |
|, . ``.... ,. .  . ,,  ` .`,.  ``,.. ``,,`,...#####  ,.`. ` ``..```..,..`.`  `,...,,.. `,..  `,`.`|
| ``. .`.,. , ,. .`.,...`,.., ```,.  ``,`   ` ,`,  ,,,``.  .`.,,..,, `,.. ,, .` ,.,,.```.`,  , .. .|
|,.`. .` , ., `,  `.`  `` `., .. ` ,..`,...., .#   #`, , .` , . .,  .`   .,,,`  .,,,. ,,,`,,..  . `|
| ..`,``, ,,``, `.``` .` `  .,`   ..  ,,`,,.`,,#   #.,`.`.,,.` ..,`,,`,` , .. ` `.  .., `,  ` ,   ,|
| .,`,..``.,. .,``. .  .``, . `.  `., ``. ``` `#####`  ,.    .,`.` ... `.., ,`,..,  , ,.` ,... ` ` |
|.,` . ,, `.,,.  .`  .  `,,``,,.., ,.`,`.  . ,,`` `.,.,`.., ..,`. ` . .``, .,  ``. ``,. ..````,,.` |
|`.,, , ,, , ..`,,`.  ``..,..`,,,.,..,,., . . `. ,``,,,... `  ` ,`,.`.  ,,`. ,``.,....```..., ..`.`|
|,`.  ``,.` ,  .,,`  .,,`.  `..,` `.`,  .``...```...`..,`,,,`..,, .  .`, ,`,.,` . , .., `,,,..,.,.,|
| `` .`.`,`,  ,, .. ,  , ,. ...`, ,,. .    `  ``,,.. ,. , `.,  . ,., ` ```,.`  ` , `,..,,,., ..`.``|
|,..` ,`,`. ,, ,  ., .,,.,. ``..```,.` .,,,.. .,``,. .`,.   `.,,  ...,``,  .`,..```. ,.,,. ``,`.  `|
|, .`,,..`.   .`,,``,`  ,.  ```. ``.``  ,,`,, `, ,`  .  ```...`, ,..`,,`. `.`,.`.,.,., , `.,  ,` . |
|.`   ``,.`.  .,  .  ,.,,, ,``..  ,`` ,`, , `. `,,. ,` ,``,,,`. ..`,,``,.` ,, `,  ,,. , `. ` ,`,.,,|
|`` `,.`,..``,.`,`... `,`.,,..,` `.```,`,.,`..,` . ,.., `,  ` ...` ,. `.,  `, ,,, ,.,.,`. . ` .,.,,|
|`,` ,.```.```.` . , . .,`,.`.``,`, ```.,  `..,.`,.`., .`  ,,.`,  ,..``..`    ,. . ,.``,..,`` `.```|
| ,.,`  .``. `` ` .,  .,.   ,.` ,`,,,  ...`, , `,.` ,, . `,, `  .  .``  ,.  ` .`,,.,,..  .  ,``..``|
| ,.`, `,... ..,...`.. ,,  `,,, ,.,`. ,.,.  `,, `.. `. `,`.. ., `,.,,`., ,,`.,. . `,,.`,, . ..` `  |
|`..`..` ``,.,  , .`,.`.,  ``..`   .,,,  ` ,` ,``..`` ,`` ,,,.` ,.,,`, .  ..`.,,`. ,, ``````,..,`..|
|,`,..  `.,``  .  ,`.`,,,,... ``,,`..`,, .`.,`` .`. ,` ,`,.  ,. ,,.``.`.`, ``.`,,  ,.`.,`` .`.. .`.|
|   ,`  ,`.``.`..  ` .. ` , `.. ,.`, `, ,.```,   ``   `.``.. `,    `. `.,, `,`` ,,`  ,,.`.`., , `,`|
|  ,,,, `,., .,`, `,..` ``` .,   `  ` `.  . ,`.,. .`, ` .,``..`, .,`.` ,`, ``, ,,,`, , ,..```,````,|
| .     .` ,` ,,, .  `.`, ``.,.. `, .,```. ,. ,. .,` ., . ``  , .,``,,,`. ``   `,,,,.. `,.. ,.`.., |
|`,,,`  ,``,,`,.`.``,` ..,`,. ,....` ,.     . ,,.``.,.``.,`  `,. . `.,`, .,,.,,` `  ,.... ,,`,...,,|
| ,`    ,,,,`  .` `,,  .,...  ` ``..`,.`..` ,..`, `. ``   ,```.,.``   .,,  ,.,`.,.`  ,``,`.`.` `...|
|,,`,,. ,`,`,, ` ` ..  `.,,,`.. ..... ....,.. ,,` . `,. ..,  . , ,`,  `.,``..`. .`` `   .  ,,`, ``,|
|`.`#####., ... ., , , `, ,,    .,.,`..,`.,  . ,.`,.`  ``,`. .,,`.,,`.,. ,,`` ` .`, .,. ,,.#####   |
|.,,` , .`` `,.` ``.``. .`,,`  ..,.  ``.,.,`.`.,, .```. .`, . ,` `` ,,,,., ``,   ,..  .,.. #   #.  |
|.  #   #`.`., ```. ``,..,,`,`.  ,`..``.,  .,` `,..` . ,.,``` ..,, .`.``.` .,` . ,  .  ` `,#   #`. |
|, .#   #, ,. ,,`. . ` , .```, .,` ```  ``  . , , .,`,,..` ,` .`.,,,   .. . `.` ,  `, ,.. . ` ., .,|
|`, #####.` ,`` .``., ,.` ,  ,, `,``.. ``..`, ..` ```` ,., ,,  ` `., ,`.`  ` , . . . `..`,.##### ``|
|``. ,,`` `.,.` ```  , , `.,,,```, ..,   ..,`  ,.. ,``..,`.,   . ` ,``,`,.``,. ` ``.. `.` `.`.`. .`|
|`,`,, ``  ..`,, . .`.,,``..,.`` `, ` ..`,`, `,`  ,`.,`  ,, . .,.. ,,,.`, ` ```.``  ```.` , `.  `` |
└==================================================================================================┘
```
