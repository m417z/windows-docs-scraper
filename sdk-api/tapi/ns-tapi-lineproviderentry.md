# LINEPROVIDERENTRY structure

## Description

The
**LINEPROVIDERENTRY** structure provides the information for a single service provider entry. An array of these structures is returned as part of the
[LINEPROVIDERLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderlist) structure returned by the function
[lineGetProviderList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproviderlist).

## Members

### `dwPermanentProviderID`

Permanent provider identifier of the entry.

### `dwProviderFilenameSize`

Size of the provider file name string, including the **null** terminator, in bytes.

### `dwProviderFilenameOffset`

Offset from the beginning of the
[LINEPROVIDERLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderlist) structure to a **null**-terminated string containing the file name (path) of the service provider DLL (.TSP) file. The size of the string is specified by **dwProviderFilenameSize**.

## Remarks

Not extensible.

## See also

[LINEPROVIDERLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderlist)

[lineGetProviderList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproviderlist)