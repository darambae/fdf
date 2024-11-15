
# FDF

## 목차

- [소개](#소개)
- [기능](#기능)
- [사용법](#사용법)
- [3D 투영](#3d-투영)
- [키보드 컨트롤](#키보드-컨트롤)
- [수학 및 공식](#수학-및-공식)
- [언어](#언어)

---

### 소개

**FDF**는 2D 고도 맵을 3D 와이어프레임으로 변환하는 프로그램으로, MiniLibX 라이브러리를 사용하여 개발되었습니다. 사용자는 실시간으로 3D 지형을 탐색하고 조작할 수 있습니다.

### 기능

- 2D 고도 맵의 3D 투영
- 고도 기반 색상 그라데이션
- 확대, 이동 및 회전 제어
- 투영 유형 조절 (등각 투영, 평행 투영)

### 사용법

**FDF**를 맵 파일과 함께 실행하려면:
```sh
./fdf 경로/맵.fdf
```

예제 `.fdf` 맵 파일은 `maps/` 디렉토리에서 테스트할 수 있습니다:
```sh
./fdf maps/42.fdf
```

### 3D 투영

**FDF**는 2D 맵에서 시각적으로 매력적인 3D 효과를 만들기 위해 등각 및 평행 투영 모드를 제공합니다.

- **등각 투영**: 3D 효과를 시뮬레이션하여 깊이를 나타내기 위해 45도 각도로 포인트를 투영합니다.
- **평행 투영**: 원근을 유지하지 않고 모든 포인트를 일정하게 유지하여 균일한 외관을 만듭니다.

### 키보드 컨트롤

- **화살표 키**: 맵 뷰를 좌우 상하로 이동합니다.
- **+ / -**: 확대 및 축소합니다.
- **W / A / S / D**: 맵 뷰를 회전합니다.
- **I / P**: 등각 투영과 평행 투영 모드 간 전환합니다.
- **Esc**: 프로그램을 종료합니다.

### 수학 및 공식

**FDF** 프로젝트는 3D 객체를 2D 화면에 렌더링하기 위해 선형 변환을 사용합니다. 아래는 핵심 개념과 적용된 수식을 설명합니다.

#### 1. 등각 투영

등각 투영은 3D 객체를 비례를 유지하면서 2D로 표현하는 방법입니다. x, y, z 축이 모두 보기 평면에 대해 동일한 각도로 기울어져 있다고 가정합니다.

주어진 3D 좌표 `(x, y, z)`를 2D 화면 좌표 `(X, Y)`에 투영하는 등각 공식은 다음과 같습니다:
  
  ```
  X = (x - y) * cos(θ)
  Y = (x + y) * sin(θ) - z
  ```

  여기서:
  - `θ`는 일반적으로 30도이며, 투영에 따라 조정 가능합니다.
  - `z`는 맵 파일의 고도를 나타냅니다.

이 공식은 **FDF**가 깊이의 환상을 만들어내며, x와 y의 다른

 오프셋을 적용하고 높이를 z 값으로 조정합니다.

#### 2. 회전

**회전**은 객체의 각 축에 따라 3D 상에서의 동적인 시야를 제공합니다. x, y, z 축에 따라 회전하는 공식은 다음과 같습니다:

- **X축 회전** (상하 기울기) :
  ```
  y' = y * cos(angle) - z * sin(angle)
  z' = y * sin(angle) + z * cos(angle)
  ```

- **Y축 회전** (좌우 회전) :
  ```
  x' = x * cos(angle) + z * sin(angle)
  z' = -x * sin(angle) + z * cos(angle)
  ```

- **Z축 회전** (평면 내 회전) :
  ```
  x' = x * cos(angle) - y * sin(angle)
  y' = x * sin(angle) + y * cos(angle)
  ```

각도 조정을 통해 사용자는 다양한 각도로 맵을 볼 수 있습니다.

#### 3. 크기 조정

**크기 조정**은 화면에 3D 객체의 확대/축소를 적용합니다. x, y, z 좌표를 크기 조정 인수 `s`로 곱하여 수행합니다:

  ```
  x' = x * s
  y' = y * s
  z' = z * s
  ```

사용자 입력에 따라 `s`를 조절하여 확대/축소를 제공합니다.

#### 4. 이동

**이동**은 객체의 형태나 방향을 바꾸지 않고 화면 상에서의 위치를 이동하는 것입니다. 예를 들어 `dx`만큼 수평 이동하고 `dy`만큼 수직 이동하려면:

  ```
  x' = x + dx
  y' = y + dy
  ```

이 방법을 통해 객체를 화면 상의 원하는 위치로 이동할 수 있습니다.

### 언어

이 README 파일은 다음 언어로도 제공됩니다:
- [영어 버전](https://github.com/darambae/fdf/readme.md)
- [프랑스어 버전](https://github.com/darambae/fdf/readme_fr.md)
