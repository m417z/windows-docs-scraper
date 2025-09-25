# NapNotifyType enumeration

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

Enumerates the types of service notifications sent by the NapAgent service. The NapAgent is also known as the Quarantine Agent.

## Constants

### `napNotifyTypeUnknown:0`

Not used.

### `napNotifyTypeServiceState:1`

NapAgent service state change notifications.

A notification of type **napNotifyTypeServiceState** is sent whenever the NapAgent service stops or starts.

### `napNotifyTypeQuarState:2`

Quarantine state change notifications.

A notification of type **napNotifyTypeQuarState** is sent whenever the isolation state changes. For more information, see [IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate).

## See also

[InitializeNapAgentNotifier](https://learn.microsoft.com/windows/desktop/NAP/initializenapagentnotifier)

[UninitializeNapAgentNotifier](https://learn.microsoft.com/windows/desktop/NAP/uninitializenapagentnotifier)