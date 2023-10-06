#pragma once

namespace Cookie
{

	struct XMFLOAT2
	{
		float x, y;
		XMFLOAT2()
		{
			x = y = 0.0f;
		}
	};
	
	struct XMFLOAT3
	{
		float x, y, z;
		XMFLOAT3()
		{
			x = y = z = 0.0f;
		}
	};

	class Vector2 : public XMFLOAT2
	{
		Vector2() {}
		Vector2(float x1, float y1) {
			x = x1;
			y = y1;
		}
	};
	
	class Vector3 : public XMFLOAT3
	{
		Vector3() {}
		Vector3(float x1, float y1, float z1) {
			x = x1;
			y = y1;
			z = z1;
		}
	};

}