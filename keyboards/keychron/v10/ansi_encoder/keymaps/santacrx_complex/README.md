# @santacrx's Keychron V10 Firmware mod
This is my customization for my v10 to maximize the capabilities plus visuals I wanted. 
This keymap attempts to have custom lighting per layer and based on what the layer contents are. 
This is a spin-off of my original layers, with a more complex change of states using the knob, thus freeing the key to the right of the rh spacebar for something else.

Basic function coloring is  still kept from `_layers`, but this is playground for using the knob to change macro and knob functionality without changing the basic keyboard ones. 
So I can have different macro layers available for regular typing, one for LabVIEW use, one for MATLAB/Simulink, one for VSCODE, and one for CAD. 
I will still have the qwerty layer and the numpad/mouse layer.
I would like to use the switch at the back for lights on/off. 

## Layers
After months of use of `_layers`, I realized that I was not using the secondary qwerty layer I had.
I also noticed that the funcionalities I wanted on my knob where limited by the setup.
Lastly, I had to sometimes reconfigure my macros in VIA just so I could be producitve that day depending on what I ws going to do. 
This keymap attempts to address all of the above, by allowing multiple knob and macro configurations based on the software package to be used.
It build up on using lights to indicate which state/layer we are in so that I can know where we are just by glancing at my keeb.


### Description
The following table described the intended layer functinality.
I made the decision to have 8 layers just beacause its a clean binary number and allows for a future addition without rework.

Layer definition:

| Bit  | Status |	Name	|	Keys	|	Macros	|	Knob	|	Lights	|
|:---:|:---:|---------|-----------|-----------|-----------|-----------|
|  0  | -- | `_FN`| _Empty_	| _Empty_	|Change M Layer|Only assinged keys|
| *1* | x01 | *`_BASE`*		| *QWERTY*		|*Typing*		|*Side Scroll*|*Regular*| 
|  2  | x06 | `_LV`	| ↑	|Labview	| 	|Reg+Green Macros|
|  3  | x0A | `_VS`		| ↑ 	|VSCode		|L/R Arrow	|Reg+Blue Macros|
|  4  | x12 | `_MAT`	| ↑ 	|Matlab		| 	|Reg+Amber Macros|
|  5  | x22 | `_CAD`		| ↑ 	|Onshape	|U/D Wheel	|Reg+Red Macros|
|  6  | x42 |			| ↑	| 	| 	|			|
|  7  | -- | `_NUM`		|NUM+MOUSE	| _Empty_	| 	|Party|

### Layout
The overall layout is as follows, based on the tabulated description above:

```
Overlay feature layer
---------------------      bit|status
       ____________        ---+------
      /           /           |
   7 /___________/_         7 |   0
      /           /           |    
   6 /___________//         6 |   0
   5 /___________// ----->  5 |   1
   4 /___________//         4 |   0
   3 /___________//         3 |   0
   2 /___________//         2 |   0
,->1 /___________/_ ----->  1 |   1
|     /           /           |
|  0 /___________/          0 |   0
|                                 +
`--- default_layer = 1            |
     layer_state   = 0x0022 <-----'
```

Layers 0 and 7 will be toggled by the FN and NUM keys respectively.
Layers 1 through 6 are the default and overlays respectively.
The cycle will be 1→0→1, or 1→7→1. 
When in 0, the knob cycles the overlay.
The Macro keys' backlighting will change according to the selected overlay setting.
When returning from 0, the respective overlay will be activated.

## Features and Functionality

### Layer Interface backbone
* Layer 1 *_BASE* set as default in initializing function
* Debugging and console enabled
* Use of `Layer_Move()` for layers 1-6
* Use of `TG()` for layers 0 *_FN* and 7 *_NUM*

### Functions

* Macro layer selector:
  * CW knob =+1 layer index, CCW =-1. 
  * [Sample](https://docs.qmk.fm/feature_layers#example-keycode-to-cycle-through-layers) used as backbone, create two keys to get that up and down
  * Case structure to handle actual layer state HEX.
    * maybe need to switch to butwise operations
* 

### Macros
* Base
  * Enhe
  * Degree symbol
  * Section symbol
* LabVIEW
  * While Loop
  * For Loop
  * Local Variable
  * Global Variable
* Matlab
  * Block comment
  * Uncomment
* CAD/OnShape
  * Pan modifier
  
### Lights

* Added some RGB_MATRIX modes that were not turned on by default
* Global layer color effects: 
  * Transparent or unsassigned keys have no backlight. 
  * CAPS only has alphas ON
* Each layer has now a visible distinction, besides the stated above:
  * `_NUM` is visibly different than the rest with rainbow pattern. 
  * `_BASE` and above, except `_NUM` 
    * share the same pattern
    * Macro column has different color based on which layer is active
  * `_FN` has diagonal to LH-HI corner (mimicking pointing to knob)

## Worflow / Desired Features / Bugs
- [x] Port over with desired layer change, test nothing broke in that port. (20240801)
  - [x] Enable Console, test output
  - [x] Disable lighting ported from `_layer`
- [ ] Layer change function:
  - [x] Create supporting functions and constants (20240801)
  - [x] Test output to console, not yet perform change (20240805)
  - [ ] Perform layer change
- [ ] Adapt lights to current layer setup
  - [x] Create debugging witnesses, test (20240802)
  - [ ] Enable functionality
  - [x] Make a Macro index group (20240805)
  - [x] Make Macro light function (20240805)
  - [ ] Test macro light

  ## Sources

  1. QMK docs
    1. [Cycle layer button](https://docs.qmk.fm/feature_layers#example-keycode-to-cycle-through-layers)
    2. [Indicators on progged keys](https://docs.qmk.fm/features/rgb_matrix#indicator-examples)
  2. Reddit
    1. [Colors per layer](https://www.reddit.com/r/olkb/comments/e0hurb/comment/fawrcem/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)
  3. Others
    1. [Macros](https://getreuer.info/posts/keyboards/macros/index.html#process_record_user-in-depth)
    2. [Rotary by layer](https://pastebin.com/rDUzHM81)
