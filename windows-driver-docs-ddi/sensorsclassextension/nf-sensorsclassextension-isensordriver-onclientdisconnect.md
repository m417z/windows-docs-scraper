# ISensorDriver::OnClientDisconnect

## Description

The **ISensorDriver::OnClientDisconnect** method notifies the sensor driver that a client application has disconnected.

## Parameters

### `pClientFile` [in]

Pointer to an [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface that represents the file object for the client that disconnected.

### `pwszSensorID` [in]

**LPWSTR** that contains the ID for the sensor from which the client application is disconnecting.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The sensor class extension calls this method in the following instances:

* An application closes normally.
* The user revokes permission for an application to access the device that contains the specified sensor.
* The cleanup work from a call to [ISensorClassExtension::CleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-cleanupfile) has completed.

You can use this call as a signal to update lists and reference counts of connected applications.

For more information about how to use this method, see [Filtering data](https://learn.microsoft.com/windows-hardware/drivers/sensors/filtering-data).

#### Examples

The following example code demonstrates an implementation of **ISensorDriver::OnClientDisconnect**. This function uses an ATL simple map, named Clients, to keep track of connected clients. See [ISensorDriver::OnClientConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientconnect) for an example of how connected clients are added to the map.

The ClientData structure is defined as follows.

```cpp
// Struct to keep track of connected client status.
struct ClientData
{
    BOOL bListening;  // Client is listening to events.
    ULONG ulInterval;  // Interval requested by client.
};
```

The function definition follows.

```cpp
HRESULT CSensorDdi:: OnClientDisconnect(
        __in IWDFFile* pClientFile,
        __in LPWSTR pwszSensorID
        )
{
    if(NULL == pClientFile ||
       NULL == pwszSensorID)
    {
        return E_POINTER;
    }

    HRESULT hr = S_OK;
    ClientData* pCD = NULL;
    BOOL bRet = FALSE;

    // Find this client in the map.
    pCD = Clients.Lookup(pClientFile);
    if(pCD == NULL)
    {
        hr = E_UNEXPECTED;
    }

    if(SUCCEEDED(hr))
    {
        // Free the client data memory.
        delete pCD;
        pCD = NULL;

        // Remove this client from the array.
        bRet = Clients.Remove(pClientFile);
        if(FALSE == bRet)
        {
            hr = E_UNEXPECTED;
        }
    }

    return hr;
}
```

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)

[ISensorDriver::OnClientConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientconnect)