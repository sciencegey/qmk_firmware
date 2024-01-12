# ErgoPlus

![ergoplus case]()

An ErgoDox-style keyboard with an extra row!
PCB files, case files, and wiring diagrams can be found [here](https://www.sciencegey.com/kb/ergoplus)

* Keyboard Maintainer: [sciencegey](https://github.com/sciencegey)
* Hardware Supported: ergoplus PCB, RP2040
* Hardware Availability: [Github](https://github.com/sciencegey/keyboards/tree/main/ergoplus)

## Flashing
First compile the firmware *(after setting up your build environment)*:

    make sciencegey/ergoplus:default
    
Then either run the flashing command, once for each half:

    make sciencegey/ergoplus:default:flash

***OR***

Enter the bootloader by either hold the **BOOT** button and plug in the keyboard half, or double-press the reset button on the back of the keyboard.

Drag the UF2 file onto the RPI-BOOT drive, repeat for the other half, and you're done!

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

---

**Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).**
