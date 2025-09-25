# WAITCHAIN_NODE_INFO structure

## Description

Represents a node in a wait chain.

## Members

### `ObjectType`

The object type. This member is one of the following values from the **WCT_OBJECT_TYPE** enumeration type.

#### WctCriticalSectionType

#### WctSendMessageType

#### WctMutexType

#### WctAlpcType

#### WctComType

#### WctThreadWaitType

#### WctProcessWaitType

#### WctThreadType

#### WctComActivationType

#### WctUnknownType

### `ObjectStatus`

The object status. This member is one of the following values from the **WCT_OBJECT_STATUS** enumeration type.

#### WctStatusNoAccess

#### WctStatusRunning

#### WctStatusBlocked

#### WctStatusPidOnly

#### WctStatusPidOnlyRpcss

#### WctStatusOwned

#### WctStatusNotOwned

#### WctStatusAbandoned

#### WctStatusUnknown

#### WctStatusError

### `LockObject`

### `LockObject.ObjectName`

The name of the object. Object names are only available for certain object, such as mutexes. If the object does not have a name, this member is an empty string.

### `LockObject.Timeout`

This member is reserved for future use.

### `LockObject.Alertable`

This member is reserved for future use.

### `ThreadObject`

### `ThreadObject.ProcessId`

The process identifier.

### `ThreadObject.ThreadId`

The thread identifier. For COM and ALPC, this member can be 0.

### `ThreadObject.WaitTime`

The wait time.

### `ThreadObject.ContextSwitches`

The number of context switches.

## See also

[GetThreadWaitChain](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-getthreadwaitchain)

[WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback)