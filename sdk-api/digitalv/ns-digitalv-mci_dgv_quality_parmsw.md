# MCI_DGV_QUALITY_PARMSW structure

## Description

The **MCI_DGV_QUALITY_PARMS** structure contains parameters for the [MCI_QUALITY](https://learn.microsoft.com/windows/desktop/Multimedia/mci-quality) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwItem`

One of the following constants indicating the type of algorithm:

| Name | Description |
| --- | --- |
| **MCI_QUALITY_ITEM_AUDIO** | Definitions are for an audio compression algorithm. |
| **MCI_QUALITY_ITEM_STILL** | Definitions are for a still video compression algorithm. |
| **MCI_QUALITY_ITEM_VIDEO** | Definitions are for a video compression algorithm. |

### `lpstrName`

String naming description.

### `lpstrAlgorithm`

String naming algorithm.

### `dwHandle`

Handle to a structure containing information describing the quality attributes.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_QUALITY_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_QUALITY](https://learn.microsoft.com/windows/desktop/Multimedia/mci-quality)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))