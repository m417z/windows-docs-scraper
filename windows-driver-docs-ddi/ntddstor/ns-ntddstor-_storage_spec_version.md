# _STORAGE_SPEC_VERSION structure

## Description

Indicates the specification of the storage device.

## Members

### `DUMMYSTRUCTNAME`

The major and minor version of the storage specification.

### `DUMMYSTRUCTNAME.MinorVersion`

The minor version of the storage specification.

### `DUMMYSTRUCTNAME.MinorVersion.DUMMYSTRUCTNAME`

The minor and sub-minor version of the storage specification.

### `DUMMYSTRUCTNAME.MinorVersion.DUMMYSTRUCTNAME.SubMinor`

The sub-minor version of the storage specification.

### `DUMMYSTRUCTNAME.MinorVersion.DUMMYSTRUCTNAME.Minor`

The minor version of the storage specification.

### `DUMMYSTRUCTNAME.MinorVersion.AsUshort`

The combination of the **Minor** and **SubMinor** versions of the storage specification.

### `DUMMYSTRUCTNAME.MajorVersion`

The major version of the storage specification.

### `AsUlong`

The combination of the **MajorVersion** and **MinorVersion** versions of the storage specification.

## Remarks

This union allows for specifying the storage specification version, such as SBC 3, SATA 3.2, and NVMe 1.2.