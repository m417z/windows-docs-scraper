## Description

The **CCAB** structure contains cabinet information.

## Members

### `cb`

The maximum size, in bytes, of a cabinet created by FCI.

### `cbFolderThresh`

The maximum size, in bytes, that a folder will contain before a new folder is created.

### `cbReserveCFHeader`

The size, in bytes, of the CFHeader reserve area. Possible value range is 0-60,000.

### `cbReserveCFFolder`

The size, in bytes, of the CFFolder reserve area. Possible value range is 0-255.

### `cbReserveCFData`

The size, in bytes, of the CFData reserve area. Possible value range is 0-255.

### `iCab`

The number of created cabinets.

### `iDisk`

The maximum size, in bytes, of a cabinet created by FCI.

### `fFailOnIncompressible`

TBD

### `setID`

A value that represents the association between a collection of linked cabinet files.

### `szDisk`

The name of the disk on which the cabinet is placed.

### `szCab`

The name of the cabinet.

### `szCabPath`

The full path that indicates where to create the cabinet.

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)