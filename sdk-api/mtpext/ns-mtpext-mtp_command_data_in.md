## Description

The **MTP_COMMAND_DATA_IN** structure contains Media Transport Protocol (MTP) custom commands that are sent to the device by using the [IWMDMDevice3::DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-deviceiocontrol) method.

## Members

### `OpCode`

Operation code.

### `NumParams`

Number of parameters passed in.

### `Params`

Parameters to the command. **MTP_COMMAND_MAX_PARAMS** is a defined constant with a value of 5.

### `NextPhase`

Indicates whether the command has a read data phase, a write data phase, or no data phase. The valid values are defined in the following table.

### `CommandWriteDataSize`

Data size of **CommandWriteData**[1], in bytes.

### `CommandWriteData`

Optional, first byte of data to write to the device if **NextPhase** is MTP_NEXTPHASE_WRITE_DATA.

## Remarks

The input buffer is expected to contain an appropriately filled out **MTP_COMMAND_DATA_IN** structure. On exit, the device driver will fill out the **MTP_COMMAND_DATA_OUT** structure and save it to the output buffer. Therefore, any request must have an input buffer of at least SIZEOF_REQUIRED_COMMAND_DATA_IN bytes, which is defined as

``` syntax
#define SIZEOF_REQUIRED_COMMAND_DATA_IN (sizeof(MTP_COMMAND_DATA_IN)-1)
```

and an output buffer of at least SIZEOF_REQUIRED_COMMAND_DATA_OUT bytes, which is defined as

``` syntax
#define SIZEOF_REQUIRED_COMMAND_DATA_OUT (sizeof(MTP_COMMAND_DATA_OUT)-1)
```

It is assumed that all commands are self-contained, that is, they can be processed completely in one call. This has implications on lengthy data transfers, because chunking in the traditional sense is not supported. (For example, to issue a read for 3megabytes, the caller would have to ensure that it allocates an output buffer of 3 MB plus SIZEOF_REQUIRED_COMMAND_DATA_OUT bytes.) Lengthy data transfers should not be done with this method, but rather through normal data-transfer APIs.

## See also

* [IWMDMDevice3::DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-deviceiocontrol)
* [MTP_COMMAND_DATA_OUT](https://learn.microsoft.com/windows/win32/api/mtpext/ns-mtpext-mtp_command_data_out)
* [Structures](https://learn.microsoft.com/windows/desktop/WMDM/structures)