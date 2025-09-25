## Description

This macro provides the following default for DRM rights

```cpp
#define DEFINE_ACXDRMRIGHTS_DEFAULT(DrmRights) const ACXDRMRIGHTS DrmRights = {FALSE, 0, FALSE}
```

## Parameters

### `DrmRights`

Specifies the DRM content rights that are assigned to the stream that is identified by ContentId. This parameter is a pointer to a [ACXDRMRIGHTS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acxdrmrights).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)