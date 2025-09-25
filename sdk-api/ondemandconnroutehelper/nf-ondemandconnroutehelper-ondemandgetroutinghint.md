# OnDemandGetRoutingHint function

## Description

The **OnDemandGetRoutingHint** function looks up a destination in the Route Request cache and, if a match is found, return the corresponding Interface ID.

## Parameters

### `destinationHostName` [in]

An PWSTR describing the target host name for a network communication.

### `interfaceIndex` [out]

The interface index of the network adapter to be used for communicating with the target host.

## Return value

This function returns the following to indicate operation results:

| Return code | Description |
| --- | --- |
| **S_OK** | A match was found in the dll cache. The *pdwInterfaceIndex* will contain the index of the interface to be used to communicate with the target host. |
| **S_FALSE** | A match was not found in the dll cache for the specified host name. |