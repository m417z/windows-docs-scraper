# _DXVA_ConfigAlphaLoad structure

## Description

The DXVA_ConfigAlphaLoad structure is sent by the host decoder to the accelerator to set the configuration for alpha-blend, texture-loading operations.

## Members

### `dwFunction`

Indicates the type of query or response when using probing and locking commands. The most significant 24 bits of **dwFunction** is the [DXVA_ConfigQueryOrReplyFlag](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-configqueryorreplyflag-and-dxva-configqueryorreplyfunc-variables) variable.

The least significant 4 bits of the *DXVA_ConfigQueryOrReplyFlag* variable contains status indicators for the query or response being performed.

The least significant 8 bits of **dwFunction** is the [bDXVA_Func variable](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) that, in this case, is equal to 2.

### `dwReservedBits`

Reserved bits used for packing and alignment. These bits are zero.

### `bConfigDataType`

Specifies the type of alpha-blend data to be used. This member can be set to one of the following values.

| **Value** | **Description** |
|:--|:--|
| 0 | 16-entry AYUV palette with [IA44](https://learn.microsoft.com/windows-hardware/drivers/) alpha-blending surface. |
| 1 | 16-entry AYUV palette with [AI44](https://learn.microsoft.com/windows-hardware/drivers/) alpha-blending surface. |
| 2 | 16-entry AYUV palette with DPXD, Highlight, and DCCMD data. |
| 3 | AYUV graphic surface. |

The preferred values for an accelerator to support for **bConfigDataType** are 1 and 3.