struct BoundingOrientedBox {
  size_t                            CORNER_COUNT;
  XMFLOAT3                          Center;
  XMFLOAT3                          Extents;
  XMFLOAT4                          Orientation;
  void                              BoundingOrientedBox() noexcept;
  void                              BoundingOrientedBox(
    const BoundingOrientedBox & unnamedParam1
  );
  BoundingOrientedBox &             operator=(
    const BoundingOrientedBox & unnamedParam1
  );
  void                              BoundingOrientedBox(
    BoundingOrientedBox && unnamedParam1
  );
  BoundingOrientedBox &             operator=(
    BoundingOrientedBox && unnamedParam1
  );
  void                              BoundingOrientedBox(
    const XMFLOAT3 & center,
    const XMFLOAT3 & extents,
    const XMFLOAT4 & orientation
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingOrientedBox & Out,
    FXMMATRIX             M
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingOrientedBox & Out,
    float                 Scale,
    FXMVECTOR             Rotation,
    FXMVECTOR             Translation
  ) noexcept;
  void                              GetCorners(
    XMFLOAT3 *Corners
  ) noexcept;
  ContainmentType XM_CALLCONV       Contains(
    FXMVECTOR Point
  ) noexcept;
  ContainmentType XM_CALLCONV       Contains(
    FXMVECTOR V0,
    FXMVECTOR V1,
    FXMVECTOR V2
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingSphere & sh
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingBox & box
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingOrientedBox & box
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingFrustum & fr
  ) noexcept;
  bool                              Intersects(
    const BoundingSphere & sh
  ) noexcept;
  bool                              Intersects(
    const BoundingBox & box
  ) noexcept;
  bool                              Intersects(
    const BoundingOrientedBox & box
  ) noexcept;
  bool                              Intersects(
    const BoundingFrustum & fr
  ) noexcept;
  bool XM_CALLCONV                  Intersects(
    FXMVECTOR V0,
    FXMVECTOR V1,
    FXMVECTOR V2
  ) noexcept;
  PlaneIntersectionType XM_CALLCONV Intersects(
    FXMVECTOR Plane
  ) noexcept;
  bool XM_CALLCONV                  Intersects(
    FXMVECTOR Origin,
    FXMVECTOR Direction,
    float &   Dist
  ) noexcept;
  ContainmentType XM_CALLCONV       ContainedBy(
    FXMVECTOR Plane0,
    FXMVECTOR Plane1,
    FXMVECTOR Plane2,
    GXMVECTOR Plane3,
    HXMVECTOR Plane4,
    HXMVECTOR Plane5
  ) noexcept;
  void                              CreateFromBoundingBox(
    BoundingOrientedBox & Out,
    const BoundingBox &   box
  ) noexcept;
  void                              CreateFromPoints(
    BoundingOrientedBox & Out,
    size_t                Count,
    const XMFLOAT3        *pPoints,
    size_t                Stride
  ) noexcept;
};