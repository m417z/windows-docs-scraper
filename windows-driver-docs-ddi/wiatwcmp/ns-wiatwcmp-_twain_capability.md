# _TWAIN_CAPABILITY structure

## Description

The TWAIN_CAPABILITY structure holds information used when a TWAIN-compatible application communicates with a WIA driver.

## Members

### `lSize`

Specifies the size, in bytes, of the TWAIN_CAPABILITY structure.

### `lMSG`

Specifies the particular TWAIN message, which can be one of the following values:

| Value | Meaning |
| --- | --- |
| MSG_GET | Get a capability. |
| MSG_GETCURRENT | Get the current capability. |
| MSG_GETDEFAULT | Get the default capability. |
| MSG_RESET | Reset the capability. |
| MSG_SET | Set a capability. |

### `lCapID`

Specifies the ID of the capability to set or get.

### `lConType`

Specifies the capability's container type.

### `lRC`

Specifies the TWAIN return code. This value can be on of the following:

| Value | Meaning |
| --- | --- |
| TWRC_FAILURE | The capability specified by the **lCapID** member is not supported. |
| TWRC_SUCCESS | The capability specified by the **lCapID** member is supported. |
| TWRC_SUCCESS | See the **Remarks** section. |

### `lCC`

Specifies the TWAIN condition code. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| TWCC_BUMMER | The operation failed for an unknown reason. |
| TWCC_SUCCESS | The operation was successful. |
| TWCC_XXX | See the **Remarks** section. |

### `lDataSize`

Specifies the size, in bytes of the data in the **Data** array.

### `Data`

Is an array that contains the capability data. The actual size, in bytes, of the array is indicated by the **lDataSize** member.

## Remarks

A TWAIN-capable application communicates with a WIA driver by way of the TWAIN compatibility later to find out whether the driver has any private capabilities, and if so, what they are. A TWAIN_CAPABILITY structure is used in this communication. For more information, see [TWAIN Compatibility](https://learn.microsoft.com/windows-hardware/drivers/image/twain-compatibility).

The TWAIN return codes and control codes are defined in *twain.h*, which can be obtained from the [TWAIN Working Group](https://www.twain.org).