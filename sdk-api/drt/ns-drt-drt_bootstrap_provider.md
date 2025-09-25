# DRT_BOOTSTRAP_PROVIDER structure

## Description

The **DRT_BOOTSTRAP_PROVIDER** structure defines the DRT interface that must be implemented by a bootstrap provider.

**Note** The DRT infrastructure does not call the methods of the bootstrap provider concurrently.

## Members

### `pvContext`

Pointer to context data that is defined by the bootstrap resolver. When creating a bootstrap resolver, the developer is required to populate the resolver with the required information; often times, this occurs as a "this" pointer. This context gets passed to all the context parameters in the functions defined by the **DRT_BOOTSTRAP_PROVIDER**.

### `Attach`

Increments the count of references for the Bootstrap Provider with a set of DRTs.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

### `Detach`

Decrements the count of references for the Bootstrap Provider with a set of DRTs.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

### `InitResolve`

Called by the DRT infrastructure to supply configuration information about upcoming name resolutions.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

#### fSplitDetect

Specifies if the resolve operation is being utilized for network split detection and recovery.

#### timeout

Specifies the maximum time a resolve should take before timing out. This value is represented in milliseconds.

#### cMaxResults

Specifies the maximum number of results to return during the resolve operation.

#### ResolveContext

Pointer to resolver specific data.

#### fFatalError

If the bootstrap provider encounters an irrecoverable error, this parameter must be set to **TRUE** when the function complete in order for the DRT to transition to the faulted state. The **HRESULT** that is made available to the higher layer application for debugging will appear in the **hr** member of the [DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data) structure associated with the event signaling the transition to the faulted state. This bootstrap provider function should not return S_OK if setting the *fFatalError* flag to **TRUE**.

### `IssueResolve`

Called by the DRT infrastructure to issue a resolution to determine the endpoints of nodes already active in the DRT cloud.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

#### pvCallbackContext

Pointer to the context data that is passed back to the callback defined by the next parameter.

#### callback

A BOOTSTRAP_RESOLVE_CALLBACK that is called back for each result and DRT_E_NO_MORE.

#### ResolveContext

Pointer to resolver specific data.

#### fFatalError

If the bootstrap provider encounters an irrecoverable error, this parameter must be set to **TRUE** when the function complete in order for the DRT to transition to the faulted state. The **HRESULT** that is made available to the higher layer application for debugging will appear in the **hr** member of the [DRT_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_event_data) structure associated with the event signaling the transition to the faulted state. This bootstrap provider function should not return S_OK if setting the *fFatalError* flag to **TRUE**.

### `EndResolve`

Ends the resolution of an endpoint.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

#### ResolveContext

The **BOOTSTRAP_RESOLVE_CONTEXT** received from the Resolve function of the specified bootstrap provider.

### `Register`

Registers an endpoint with the bootstrapping mechanism. This process makes it possible for other nodes find the endpoint via the bootstrap resolver.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.

#### pAddressList

Pointer to the list of addresses to register with the bootstrapping mechanism.

### `Unregister`

This function deregisters an endpoint with the bootstrapping mechanism. As a result, other nodes will be unable to find the local node via the bootstrap resolver.

#### pvContext

Contains the **pvContext** value from **DRT_BOOTSTRAP_PROVIDER**.