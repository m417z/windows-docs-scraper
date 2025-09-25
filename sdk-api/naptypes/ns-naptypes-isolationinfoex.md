# IsolationInfoEx structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **IsolationInfoEx** structure defines the extended isolation status of the machine or the connection.

## Members

### `isolationState`

An [IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate) value that contains the isolation state of a machine.

### `extendedIsolationState`

An [ExtendedIsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-extendedisolationstate) value that contains the extended isolation state of a machine.

### `probEndTime`

A [ProbationTime](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) value that contains the time at which a machine should come out from probation.

### `failureUrl`

A [CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring) value that contains a URL to navigate to in the event of failure.

## See also

[CountedString](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-countedstring)

[ExtendedIsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-extendedisolationstate)

[IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate)

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)