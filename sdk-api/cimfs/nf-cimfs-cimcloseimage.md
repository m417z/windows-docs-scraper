## Description

Frees resources associated with the image handle.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**

An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.

## Remarks

If the image handle is closed before it is committed, any modifications performed on the image using the image handle are discarded. If a stream handle exists for the image, the image resources will not be freed until the stream handle is closed.

## See also