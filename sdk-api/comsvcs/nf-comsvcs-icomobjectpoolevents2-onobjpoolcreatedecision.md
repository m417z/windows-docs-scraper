# IComObjectPoolEvents2::OnObjPoolCreateDecision

## Description

Generated when a pool provides a requesting client with an existing object or creates a new one.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `dwThreadsWaiting` [in]

The number of threads waiting for an object.

### `dwAvail` [in]

The number of free objects in the pool.

### `dwCreated` [in]

The number of total objects in the pool.

### `dwMin` [in]

The pool's minimum object value.

### `dwMax` [in]

The pool's maximum object value.

## Return value

The user verifies the return values from this method.

## Remarks

When a component is configured for object pooling, the pool is populated with objects up to the specified minimum level. As client requests for the component come in, they are satisfied on a first-come first-served basis from the pool. If no pooled objects are available and the pool is not yet at its specified maximum level, a new object is created and activated for the client.

## See also

[IComObjectPoolEvents2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents2)