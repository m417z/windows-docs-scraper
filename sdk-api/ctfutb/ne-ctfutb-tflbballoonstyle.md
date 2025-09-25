# TfLBBalloonStyle enumeration

## Description

Elements of the **TfLBBalloonStyle** enumeration are used to specify a language bar balloon style.

## Constants

### `TF_LB_BALLOON_RECO:0`

This balloon style is used to represent a reconversion operation.

### `TF_LB_BALLOON_SHOW:1`

This is a normal balloon style.

### `TF_LB_BALLOON_MISS:2`

This balloon style is used to indicate that a command was not recognized.

## Remarks

The following image shows an example of a balloon with the TF_LB_BALLOON_RECO style.

![TF_LB_BALLOON_RECO balloon](https://learn.microsoft.com/windows/win32/api/ctfutb/images/Balloon_RECO.gif)
The following image shows an example of a balloon with the TF_LB_BALLOON_SHOW style.

![TF_LB_BALLOON_SHOW balloon](https://learn.microsoft.com/windows/win32/api/ctfutb/images/Balloon_SHOW.gif)
The following image shows an example of a balloon with the TF_LB_BALLOON_MISS style.

![TF_LB_BALLOON_MISS balloon](https://learn.microsoft.com/windows/win32/api/ctfutb/images/Balloon_MISS.gif)

## See also

[ITfFnBalloon::UpdateBalloon](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnballoon-updateballoon)

[TF_LBBALLOONINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_lbballooninfo)