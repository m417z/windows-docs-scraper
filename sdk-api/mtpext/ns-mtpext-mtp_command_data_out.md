## Description

The **MTP_COMMAND_DATA_OUT** structure contains Media Transport Protocol (MTP) responses that are filled by the device driver on exiting a call to [IWMDMDevice3::DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-deviceiocontrol).

## Members

### `ResponseCode`

Response code.

### `NumParams`

Number of parameters for this response.

### `Params`

Parameters of the response. **MTP_RESPONSE_MAX_PARAMS** is a defined constant with a value of 5.

### `CommandReadDataSize`

Data size of **CommandReadData**[1], in bytes.

### `CommandReadData`

Optional, first byte of data to read from the device if **MTP_COMMAND_DATA_IN.NextPhase** is MTP_NEXTPHASE_READ_DATA.

## Remarks

The input buffer is expected to contain an appropriately filled out [MTP_COMMAND_DATA_IN](https://learn.microsoft.com/windows/desktop/api/mtpext/ns-mtpext-mtp_command_data_in) structure. On exit, the device driver will fill out the **MTP_COMMAND_DATA_OUT** structure and save it to the output buffer. Therefore, any request must have an input buffer of at least SIZEOF_REQUIRED_COMMAND_DATA_IN bytes, which is defined as the following:

``` syntax
#define SIZEOF_REQUIRED_COMMAND_DATA_IN (sizeof(MTP_COMMAND_DATA_IN)-1)
```

Any request must also have an output buffer of at least SIZEOF_REQUIRED_COMMAND_DATA_OUT bytes, which is defined as the following:

``` syntax
#define SIZEOF_REQUIRED_COMMAND_DATA_OUT (sizeof(MTP_COMMAND_DATA_OUT)-1)
```

It is assumed that all commands are self-contained, that is, they can be processed completely in one call. This has implications on lengthy data transfers, because chunking in the traditional sense is not supported. (For example, to issue a read for 3megabytes, the caller would have to ensure that it allocates an output buffer of 3 MB plus **SIZEOF_REQUIRED_COMMAND_DATA_OUT** bytes.) Lengthy data transfers should not be done with this method, but rather through normal data transfer APIs.

## See also

[IWMDMDevice3::DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-deviceiocontrol)

[MTP_COMMAND_DATA_IN](https://learn.microsoft.com/windows/desktop/api/mtpext/ns-mtpext-mtp_command_data_in)

[Structures](https://learn.microsoft.com/windows/desktop/WMDM/structures)