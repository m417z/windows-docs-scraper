## Description

The **KS_COPY_MACROVISION** structure specifies the Macrovision level of the data stream.

## Members

### `MACROVISIONLevel`

Specifies the Macrovision level. This must be one of the following values from the **KS_COPY_MACROVISION_LEVEL** enumeration:

| Level | Meaning |
|---|---|
| KS_MACROVISION_DISABLED | Indicates that Macrovision copyright protection should not be in effect. |
| KS_MACROVISION_LEVEL1 | Indicates that Macrovision level 1 copyright protection must be in effect. |
| KS_MACROVISION_LEVEL2 | Indicates that Macrovision level 2 copyright protection must be in effect. |
| KS_MACROVISION_LEVEL3 | Indicates that Macrovision level 3 copyright protection must be in effect. |

## Remarks

The KS_COPY_MACROVISION structure is used by the KSPROPERTY_COPY_MACROVISION property.

For additional uses of this structure see [DVD Copyright Protection](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-copyright-protection) and [Macrovision](https://learn.microsoft.com/windows-hardware/drivers/stream/macrovision).

## See also

[KSPROPERTY_COPY_MACROVISION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-copy-macrovision)