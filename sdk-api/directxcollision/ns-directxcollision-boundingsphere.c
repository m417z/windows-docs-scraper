struct BoundingSphere {
  XMFLOAT3                          Center;
  float                             Radius;
  void                              BoundingSphere() noexcept;
  void                              BoundingSphere(
    const BoundingSphere & unnamedParam1
  );
  BoundingSphere &                  operator=(
    const BoundingSphere & unnamedParam1
  );
  void                              BoundingSphere(
    BoundingSphere && unnamedParam1
  );
  BoundingSphere &                  operator=(
    BoundingSphere && unnamedParam1
  );
  void                              BoundingSphere(
    const XMFLOAT3 & center,
    float            radius
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingSphere & Out,
    FXMMATRIX        M
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingSphere & Out,
    float            Scale,
    FXMVECTOR        Rotation,
    FXMVECTOR        Translation
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
  void                              CreateMerged(
    BoundingSphere &       Out,
    const BoundingSphere & S1,
    const BoundingSphere & S2
  ) noexcept;
  void                              CreateFromBoundingBox(
    BoundingSphere &    Out,
    const BoundingBox & box
  ) noexcept;
  void                              CreateFromBoundingBox(
    BoundingSphere &            Out,
    const BoundingOrientedBox & box
  ) noexcept;
  void                              CreateFromPoints(
    BoundingSphere & Out,
    size_t           Count,
    const XMFLOAT3   *pPoints,
    size_t           Stride
  ) noexcept;
  void                              CreateFromFrustum(
    BoundingSphere &        Out,
    const BoundingFrustum & fr
  ) noexcept;
};