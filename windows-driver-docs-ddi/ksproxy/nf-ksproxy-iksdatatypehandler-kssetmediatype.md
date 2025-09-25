## Description

The **KsSetMediaType** method sets the media type for a data type handler.

## Parameters

### `AmMediaType` [in]

Defines the **AM_MEDIA_TYPE** parameter *AmMediaType*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

Clients can call **KsSetMediaType** of a single data type handler to initialize this data type handler to a particular media type from a group of many disparate media types.

## See also

[IKsDataTypeHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksdatatypehandler)