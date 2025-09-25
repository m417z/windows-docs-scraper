# MbbAdapterGetSessionId function

## Description

The **MbbAdapterGetSessionId** method retrieves the data session ID represented by the given NETADAPTER object.

## Parameters

### `Adapter`

A handle to a NetAdapterCx NETADAPTER object previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate) and initialized with [**MbbAdapterInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbadapterinitialize).

## Return value

Returns the data session's ID to the network interface represented by the NETADAPTER object.

## Remarks

The client driver must call [**MbbAdapterInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbadapterinitialize) first before calling this method.

For more information, see [Creating the NetAdapter interface for the PDP context/EPS bearer](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#creating-the-netadapter-interface-for-the-pdp-contexteps-bearer).

## See also