## Description

The **AcxMicArrayGeometryAddMicrophoneCoordinates** function adds physical coordinates to a microphone array geometry.

## Parameters

### `MicArrayGeometry` [in]

The ACX_MIC_ARRAY_GEOMETRY object to which the new coordinates are to be added. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `MicrophoneCoordinates` [in]

An array of [ACX_MICROPHONE_COORDINATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_microphone_coordinates) to add to the microphone array geometry.

### `MicrophoneCoordinatesCount` [in]

The number of coordinates to add.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry)
- [ACX_MICROPHONE_COORDINATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_microphone_coordinates)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)