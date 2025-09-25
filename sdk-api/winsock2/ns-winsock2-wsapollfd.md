# WSAPOLLFD structure

## Description

The **WSAPOLLFD** structure stores socket information used by the [WSAPoll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsapoll) function.

## Members

### `fd`

Type: **SOCKET**

The identifier of the socket for which to find status. This parameter is ignored if set to a negative value. See Remarks.

### `events`

Type: **short**

A set of flags indicating the type of status being requested. This must be one or more of the following.

| Flag | Meaning |
| --- | --- |
| POLLPRI | Priority data may be read without blocking. This flag is not supported by the Microsoft Winsock provider. |
| POLLRDBAND | Priority band (out-of-band) data can be read without blocking. |
| POLLRDNORM | Normal data can be read without blocking. |
| POLLWRNORM | Normal data can be written without blocking. |

The POLLIN flag is defined as the combination of the **POLLRDNORM** and **POLLRDBAND** flag values. The POLLOUT flag is defined as the same as the **POLLWRNORM** flag value.

### `revents`

Type: **short**

A set of flags that indicate, upon return from the [WSAPoll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsapoll) function call, the results of the status query. This can a combination of the following flags.

| Flag | Description |
| --- | --- |
| POLLERR | An error has occurred. |
| POLLHUP | A stream-oriented connection was either disconnected or aborted. |
| POLLNVAL | An invalid socket was used. |
| POLLPRI | Priority data may be read without blocking. This flag is not returned by the Microsoft Winsock provider. |
| POLLRDBAND | Priority band (out-of-band) data may be read without blocking. |
| POLLRDNORM | Normal data may be read without blocking. |
| POLLWRNORM | Normal data may be written without blocking. |

The POLLIN flag is defined as the combination of the **POLLRDNORM** and **POLLRDBAND** flag values. The POLLOUT flag is defined as the same as the **POLLWRNORM** flag value.

For sockets that do not satisfy the status query, and have no error, the **revents** member is set to zero upon return.

## Remarks

The **WSAPOLLFD** structure is defined on Windows Vista and later.

The **WSAPOLLFD** structure is used by the [WSAPoll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsapoll) function to determine the status of one or more sockets. The set of sockets for which status is requested is specified in *fdarray* parameter, which is an array of **WSAPOLLFD** structures. An application sets the appropriate flags in the **events** member of the **WSAPOLLFD** structure to specify the type of status requested for each corresponding socket. The **WSAPoll** function returns the status of a socket in the **revents** member of the **WSAPOLLFD** structure.

If the **fd** member of the **WSAPOLLFD** structure is set to a negative value, the structure is ignored by the [WSAPoll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsapoll) function call, and the **revents** member is cleared upon return. This is useful to applications that maintain a fixed allocation for the *fdarray* parameter of **WSAPoll**; such applications need not waste resources compacting elements of the array for unused entries or reallocating memory. It is unnecessary to clear the **revents** member prior to calling the **WSAPoll** function.

## See also

[WSAPoll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsapoll)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)