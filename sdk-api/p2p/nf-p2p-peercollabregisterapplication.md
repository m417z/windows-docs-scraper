# PeerCollabRegisterApplication function

## Description

The **PeerCollabRegisterApplication** function registers an application with the local computer so that it can be launched in a peer collaboration activity.

## Parameters

### `pcApplication` [in]

Pointer to a [PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info) structure that contains the UUID of the peer's application feature set as well as any additional peer-specific data.

### `registrationType` [in]

A [PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type) value that describes whether the peer's application is registered to the **current user** or **all users** of the peer's machine.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

An *application* is a set of software or software features available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

The collaboration infrastructure can receive application invites from trusted contacts or from "People Near Me", which are based on the scope the collaboration infrastructure is signed in with using PeerCollabSignin.

A peer's application has a GUID representing a single specific application. When an application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To unregister a peer's application, call [PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication) with this GUID.

When registering an application, it is recommended that developers specify a relative path, such as **%ProgramFiles%**, instead of an absolute path. This prevents application failure due to a change in the location of application files. For example, if the **C:\ProgramFiles** directory is moved to **E:\\**.

Only applications that are local to the machine can be registered. It is not possible to register when an application's executable path is located on a network share like a UNC path or locally-mapped network drive.

Applications can be registered in the 'ALL_USERS' and 'CURRENT_USER' scopes. In the event an application is registered in both scopes simultaneously, an application registered in 'CURRENT_USER' scope takes precedence over an application registered in 'ALL_USERS' scope.
It is important to note that to register for the registration type of 'ALL_USERS' the caller must be operating with administrative privileges.

The maximum number of applications that can be registered for a specific *registrationType* is 64.

## See also

[PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication)