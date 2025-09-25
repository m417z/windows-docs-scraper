# COMSVCSEVENTINFO structure

## Description

Represents contextual information about an event, such as the time it was generated and which process server and COM+ application generated it.

## Members

### `cbSize`

The size of this structure, in bytes.

### `dwPid`

The process ID of the server application from which the event originated.

### `lTime`

The coordinated universal time of the event, as seconds elapsed since midnight, January 1, 1970.

### `lMicroTime`

The microseconds added to **lTime** for time to microsecond resolution.

### `perfCount`

The value of the high-resolution performance counter when the event originated.

### `guidApp`

The applications globally unique identifier (GUID) for the first component instantiated in **dwPid**. If you are subscribing to an administration interface or event and the event is not generated from a COM+ application, this member is set to zero.

### `sMachineName`

The fully qualified name of the computer where the event originated.

## See also

[IComActivityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomactivityevents)

[IComApp2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomapp2events)

[IComAppEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomappevents)

[IComCRMEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomcrmevents)

[IComExceptionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomexceptionevents)

[IComIdentityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomidentityevents)

[IComInstance2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icominstance2events)

[IComInstanceEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icominstanceevents)

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)

[IComMethod2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icommethod2events)

[IComMethodEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icommethodevents)

[IComObjectConstruction2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectconstruction2events)

[IComObjectConstructionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectconstructionevents)

[IComObjectEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectevents)

[IComObjectPool2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpool2events)

[IComObjectPoolEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents)

[IComObjectPoolEvents2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents2)

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)

[IComResourceEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomresourceevents)

[IComSecurityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomsecurityevents)

[IComThreadEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomthreadevents)

[IComTrackingInfoEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtrackinginfoevents)

[IComTransaction2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransaction2events)

[IComTransactionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransactionevents)

[IComUserEvent](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomuserevent)