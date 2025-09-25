## Description

The **FNFCISTATUS** macro provides the declaration for the application-defined callback function to update the user.

## Parameters

### `fn`

Indicates the type of status update. Possible values include:

| Value | Meaning |
| --- | --- |
| statusFile0x00 | Compressing a block into a folder. |
| statusFolder0x01 | Adding a folder to a cabinet. |
| statusCabinet0x02 | Writing out a complete cabinet. |

## Remarks

If *typeStatus* equals **statusCabinet** the returned value indicates the desired size for the cabinet file. FCI updates the maximum cabinet size remaining using this returned value. This allows a client to generate multiple cabinets per disk, and have FCI limit the size accordingly.

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)