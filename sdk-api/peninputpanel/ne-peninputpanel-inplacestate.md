# InPlaceState enumeration

## Description

Specifies the In-Place state values of the Tablet PC Input Panel.

## Constants

### `InPlaceState_Auto:0`

The system decides which In-Place state of the Input Panel is the most appropriate.

### `InPlaceState_HoverTarget:1`

 The Input Panel Icon appears. The expanded Input Panel will not appear.

### `InPlaceState_Expanded:2`

The In-Place Input Panel always appears expanded, rather than the Input Panel Icon appearing first and then requiring the user to tap the Input Panel Icon before Input Panel expands.

## Remarks

The system default is for the In-Place Input Panel to appear in the hover state unless Input Panel is already visible in the expanded state, in which case Input Panel remains expanded.