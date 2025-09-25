# WofShouldCompressBinaries function

## Description

Indicates whether compression should be used on a particular volume, and if so, which compression algorithm should be used.

## Parameters

### `Volume` [in]

Specifies the path to the volume whose compression state is desired.

### `Algorithm` [out]

Points to a ULONG value. If the function returns TRUE, indicating compression is desired, this value will contain the algorithm that should be used for this volume.

## Return value

If binaries on this volume should be compressed, the return value is TRUE; otherwise it is FALSE. This function will return FALSE if the system does not support compression on the specified volume.