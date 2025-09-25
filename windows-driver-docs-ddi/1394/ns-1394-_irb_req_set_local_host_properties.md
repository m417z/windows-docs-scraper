# _IRB_REQ_SET_LOCAL_HOST_PROPERTIES structure

## Description

This structure contains the fields required to carry out a SetLocalHostProperties request.

## Members

### `nLevel`

Specifies what level of information is desired from this call. The following flags are provided.

| Flag | Description |
| --- | --- |
| SET_LOCAL_HOST_PROPERTIES_GAP_COUNT | Sets a lower bound on the value the bus uses for its gap count. See the *IEEE 1394-1995 Specification* for a description of the gap count. |
| SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM | Used to add or remove unit directories. This request cannot be used to modify instance directories or root keys in the configuration ROM. |

### `Information`

Points to an information block to be filled in. The information returned depends on the value in **u.SetLocalHostProperties.nLevel**. Each block has its own particular structure.

| Flag | Structure |
| --- | --- |
| SET_LOCAL_HOST_PROPERTIES_GAP_COUNT | SET_LOCAL_HOST_PROPS2 |
| SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM | SET_LOCAL_HOST_PROPS3 |