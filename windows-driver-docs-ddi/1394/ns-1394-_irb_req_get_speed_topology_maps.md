# _IRB_REQ_GET_SPEED_TOPOLOGY_MAPS structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a GetSpeedTopologyMaps request.

## Members

### `SpeedMap`

Points to the SPEED_MAP structure of the bus. This member is filled on completion.

### `TopologyMap`

Points to the TOPOLOGY_MAP structure of the bus. The topology map will be in big-endian, irrespective of the byte order of the local node. This member is filled on completion.