# LDAP_TIMEVAL structure

## Description

The **LDAP_TIMEVAL** structure is used to represent an interval of time.

## Members

### `tv_sec`

Time interval, in seconds.

### `tv_usec`

Time interval, in microseconds.

## Remarks

The **LDAP_TIMEVAL** structure specify both local timeouts and timeouts sent to the server. The exact usage is described in each LDAP function where used.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[Searching a Directory](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-a-directory)