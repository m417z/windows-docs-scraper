# KSPROPERTY_DROPPEDFRAMES_CURRENT_S structure

## Description

The KSPROPERTY_DROPPEDFRAMES_CURRENT_S structure describes the dropped frame information from the minidriver.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `PictureNumber`

Specifies the current picture number provided by the minidriver. This value is the sum of the number of frames captured plus the number of frames dropped. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `DropCount`

Specifies the count of dropped frames, which is provided by the minidriver. This counter increments whenever the minidriver was scheduled to capture a frame, but failed to do so, for example, because of buffer starvation. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `AverageFrameSize`

Specifies the average size of frames captured. This value is provided by the minidriver.

## Remarks

For more information about updating **PictureNumber** and **DropCount** see [Capturing Video](https://learn.microsoft.com/windows-hardware/drivers/stream/capturing-video).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_DROPPEDFRAMES_CURRENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-droppedframes-current)

[PROPSETID_VIDCAP_DROPPEDFRAMES](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-droppedframes)