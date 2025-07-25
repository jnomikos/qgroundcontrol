# PX4 비행 모드 설정

The _Flight Modes_ section allows you to configure which [flight modes](http://docs.px4.io/main/en/getting_started/flight_modes.html) and other actions are triggered by particular switches/switch positions on your RC transmitter.

::: info
In order to set up flight modes you must already have

- 비행 모드를 설정하려면 비행 모드를 설정하기 위해 [무전기를 구성](../setup_view/radio.md)해야 합니다.
- - [RC 송신기 설정](../setup_view/FlightModes.md#transmitter-setup)(비행 모드 & 송신기 설정)

이 섹션에 액세스하려면, 상단 툴바에서 **기어** 아이콘(차량 설정)을 선택한 다음 사이드바에서 **비행 모드**를 선택하세요.

![비행 모드 단일 채널](../../../assets/setup/flight_modes/px4_single_channel.jpg)

## 비행 모드 설정

화면에서 "모드" 채널을 지정하고 채널에서 전송된 값을 기반으로 활성화될 최대 6개의 비행 모드를 선택할 수 있습니다.
또한 소수의 채널을 할당하여 랜딩 기어 배치 또는 비상 정지(킬 스위치)와 같은 특정 작업을 트리거할 수 있습니다.

단계는 다음과 같습니다:

1. RC 송신기를 켭니다.

2. 상단 툴바에서 **기어** 아이콘(차량 설정)을 선택한 다음 사이드바에서 **비행 모드**를 선택합니다.

  ![비행 모드 단일 채널](../../../assets/setup/flight_modes/px4_single_channel.jpg)

3. _비행 모드 설정_ 설정

  - 송신기 **모드 채널**을 선택합니다(위의 채널 5로 표시됨).
  - 채널에 인코딩된 스위치 위치에 대해 최대 6개의 **비행 모드**를 선택합니다.

    ::: info
    Position mode, return mode and mission mode [are recommended](https://docs.px4.io/main/en/config/flight_mode.html#what-flight-modes-and-switches-should-i-set).
    :::

4. _스위치 설정_ 설정

  - _킬 스위치_, 랜딩 기어 등 특정 작업에 매핑하려는 채널을 선택합니다(트랜스미터에 예비 스위치와 채널이 있는 경우).

5. 모드가 올바른 송신기 스위치에 매핑되었는 지 테스트합니다.
  - _채널 모니터_를 확인하여 각 스위치가 예상 채널을 이동하는 지 확인합니다.
  - 송신기의 각 모드 스위치를 차례로 선택하고 원하는 비행 모드가 활성화되어 있는 지 확인합니다(활성 모드의 경우 _QGroundControl_에서 텍스트가 노란색으로 변경됩니다).

모든 값은 변경시에 자동으로 저장됩니다.

## See Also

- [PX4 비행 모드 ](https://docs.px4.io/en/flight_modes/)
