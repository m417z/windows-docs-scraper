# RAS_PROJECTION_INFO structure

## Description

The **RAS_PROJECTION_INFO** structure contains the Point-to-Point (PPP) or Internet Key Exchange version 2 (IKEv2) projection information for a RAS connection.

## Members

### `version`

A [RASAPIVERSION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd408102(v=vs.85)) value that specifies the structure version.

### `type`

A [RASPROJECTION_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ras/ne-ras-rasprojection_info_type) value that specifies the connection type in **union**.

### `ppp`

### `ikev2`

#### - union

#### ppp

A [RASPPP_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-rasppp_projection_info) structure that contains the PPP projection information of a RAS connection.

#### ikev2

A [RASIKEV2_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-rasikev2_projection_info) structure that contains the IKEv2 projection information of a RAS connection.

## See also

[RasGetProjectionInfoEx](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetprojectioninfoex)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Structures](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-structures)