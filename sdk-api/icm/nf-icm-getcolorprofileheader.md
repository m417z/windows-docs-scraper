## Description

Retrieves or derives ICC header structure from either ICC color profile or WCS XML profile. Drivers and applications should assume returning **TRUE** only indicates that a properly structured header is returned. Each tag will still need to be validated independently using either legacy ICM2 APIs or XML schema APIs.

## Parameters

### `hProfile`

Specifies a handle to the color profile in question.

### `pHeader`

Points to a variable in which the ICC header structure is to be placed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. This function will fail is an invalid ICC or WCS XML profile is referenced in the hProfile parameter. For extended error information, call **GetLastError**.

## Remarks

To determine whether the header is derived from an ICC or DMP profile handle, check the header signature (header bytes 36-39). If the signature is "acsp" (big endian) then an ICC profile was used. If the signature is "cdmp" (big-endian) then a DMP was used.

The distinguishing features that identify a header as having been "synthesized" for a WCS DMP are:

pIcmProfileHeader->phSignature = 'pmdc' (little endian = big endian 'cdmp')

pIcmProfileHeader->phCMMType = '1scw' (little endian = big endian 'wcs1').

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [PROFILEHEADER](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-profileheader)