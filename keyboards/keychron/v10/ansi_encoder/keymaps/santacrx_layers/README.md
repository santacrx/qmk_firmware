# @santacrx's Keychron V10 Firmware mod
This is my customization for my v10 to maximize the capabilities plus visuals I wanted. This keymap attempts to have custom lighting per layer and based on what the layer contents are.

## Current Features
* 4 layers
  * _Base windows qwerty layer
  * _F1 normal functions
  * _F2 alternate querty and other functions. Mainly a different setting for the knob
  * _Numpad and mouse
* Added some RGB_MATRIX modes that were not turned on by default
* Global layer color effects: 
  * Transparent or unsassigned keys have no backlight. 
  * CAPS only has alphas ON
* Each layer has now a visible distinction, besides the stated above:
  * _NUM is visibly different than the rest with rainbow pattern. 
  * _BASE to any of the _FNs changes the hue between each. Color change plus OFF keys lets me know on which layer I am on.

## Worflow / Desired Features / Bugs
- [x] Commit of first working version (2024-04-05)
- [x] Change base color to other than white (2024-04-10)
- [x] Build a way to keep lightning changes made in L3 stick for L0 and not reset to the default (2024-04-10)
- [x] Correct bug where _NUM doesn't change hue
- [x] Make _NUM only light up actual keycodes (last commit, check date)
- [x] _NUM is now rainbow pinwheel always, but updates to layers there will reflect to the others (2024-07-09)
- [ ] Fix the issue to return to the previous _BASE hue from any of the function layers

## Deprecated  Features
* Each layer has its own color scheme, adapted from [here]{https://www.reddit.com/r/olkb/comments/e0hurb/comment/fawrcem/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button}
- [-] *MOVED TO SEPARATE DEV* Party mode caps lock or numpad as seen [here]{http://daedalusrising.com/2019/10/07/the-massdrop-alt-custom-animations-and-more/}