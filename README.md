# ゆびトーン（開発名：MenZ-TONE） #
***

|初心者工作|お手軽演奏|ポータブル|
|:---:|:---:|:---:|
|程よい難易度！|指一本でカンタン演奏！|ポケットサイズ！|

[![IMAGE ALT TEXT](https://img.youtube.com/vi/ij7eNtTbqwg/0.jpg)](https://www.youtube.com/watch?v=ij7eNtTbqwg "Youtube video")

### これは何？ ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_real.jpg" width="50%" align="right" alt="MenZ-TONE実物">
世界最小の音ゲーマシン！<br>
ボタン一つに、圧電ブザー、スコアは自分の満足感！<br>
楽器が何もできないのに、音楽を演奏したいヤツ必見！<br>
指一本でカンタンに演奏できるぞ！<br>

<br clear="all">

### 特徴 ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_circuit.png" width="50%" align="right" alt="MenZ-TONE回路図">
1鍵盤だけで曲を奏でる！<br>
それっぽいタイミングでキーを押していけば ゆびトーン が勝手に演奏！<br>
ゆびトーンに10曲収録しています！<br>
ArduinoUNO を使えば MIDI や MML からコンバートして好きな曲を収録することも可能！<br>

<br clear="all">

### 内容物 ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/e60dfb00fbc16afa9d4a3ec3e0ca0d44dbfe4d77/photo/MenZ-TONE_contents.JPG" alt="MenZ-TONE内容物">
<br>

|名前|個数|備考|
|:---:|:---:|:---:|
|基板|1|ゆびトーン専用|
|ATmega328P|1|ゆびトーン書き込み済み|
|水晶発振子|1|16MHz|
|セラミックコンデンサ|2|22pF|
|セラミックコンデンサ|1|0.1uF|
|電解コンデンサ|1|47uF|
|抵抗|1|330Ω|
|抵抗|4|10kΩ|
|抵抗|8|7セグLEDによって抵抗値変更|
|タクトスイッチ(大)|1|演奏用|
|タクトスイッチ(小)|3|その他操作用|
|発光ダイオード|1|PIN13用|
|発光ダイオード|1|演奏スイッチ用|
|7セグメントLED|1|アノードコモン|
|圧電ブザー|1||

<br clear="all">

### 使用する工具 ###

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_tool.JPG" width="50%" align="right" alt="使用する工具">

（左から）

1. ハンダコテ
2. ハンダ

   はんだ付けには上2つが必須！熱が出るので、やけどに十分して工作しよう！

3. ニッパー

   はんだ付けしたあとの部品の足をこれで切り取ろう！

<br clear="all">

### 工作時の注意 ###

* 付属のマニュアルをよく読んで製作を行ってください
* 工作時は工具による怪我、やけど等に十分注意して行いましょう
* 保護者の方へ：お子様が製作を行う場合は、指導・監督や保護メガネ等の保護具等で安全を確保した上で製作をさせてください

<br clear="all">

### 曲リスト ###

|番号|曲名|難易度（多いほど難しい）|
|:---:|:---:|:---:|
|0|オチに使われる効果音|☆|
|1|チャルメラ|☆|
|2|きらきら星|☆☆|
|3|遠き山に日は落ちて|☆☆|
|4|赤い靴|☆☆|
|5|カエルの歌|☆☆|
|6|君が代|☆☆☆|
|7|通りゃんせ|☆☆☆☆|
|8|かごめかごめ|☆☆☆☆☆|
|9|Auld Lang Syne（蛍の光）|☆☆|

### 他の曲は無いの？ ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_kit.jpg" width="50%" align="right" alt="MenZ-TONE回路図">
MMLデータをゆびトーン用のデータにコンバートするツールを作りました<br>
http://www.the-menz.com/mml2tone.html <br>
 <br>
songs.hに自動演奏データや曲データが入っています<br>
これを書き換えてArduinoに書き込みましょう<br>
 <br>
MIDI -> MML -> TONE の流れでMIDIからTONEに自動演奏&曲データを流し込めます<br>
 <br>
MIDIからMMLに変換するには 3ML EDITOR 2 が便利です<br>
http://3ml.jp/

<br clear="all">

#### MIDIからMMLに変換する ####

1. 3ML EDITOR 2でMIDIファイルを開きます

   「ファイル」＞「標準MIDIファイルを入力」を選択して、ファイルを開きます

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_3mleditor.jpg" width="430px" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_openmidi.jpg" width="430px">

2. 「インポート設定」の画面でOKをクリックします。

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/a3f341c478608d9ff0e374d6dd382beaa2d9c14f/photo/MenZ-TOME_midiconfig.jpg">

3. Tempoの部分にある数字をメモっておきます

   例では100となっています

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_tempo.jpg">

4. メロディ部分のスコアを開き、使いたい部分のメロディーを選択してコピーします

   例では3小節途中までを選択しました

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_score.jpg">

5. MMLを全て削除してコピーしたMMLを貼り付けた後、コメントや改行を削除し1行にして、先頭にテンポを追加します

   テンポは100なので、MMLの先頭にt100を書きます

   1行にしたものをこのあとの作業に使用しますので、コピーしておきます

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TOME_addtempo.jpg">

<br clear="all">

#### MMLからゆびトーンの形式に変換する ####

1. 3ML EDITOR 2で仕込んだMMLを[MML2TONE](https://www.the-menz.com/mml2tone.html)のテキストボックスに入れてconvert!ボタンを押します

   以下の3つの情報がでてきますので、これをこのあとの作業に使います。

   1. テンポ
   2. 配列形式の楽譜
   3. 配列形式の音符の長さ

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_mml3tone.png">

<br clear="all">

#### 曲をプログラムに追加する ####

例では、song2.hの1曲目を変更します。

1. ヘッダファイルを開きます

2. 楽譜を置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_scorecode.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_scorecode_change.png">

3. テンポを置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/eb2721cc86852d9137bde1473b83cffd58a12677/photo/MenZ-TONE_tempo.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/eb2721cc86852d9137bde1473b83cffd58a12677/photo/MenZ-TONE_tempo_change.png">
<br>

4. 音符の長さを置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_length.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/8e4a96d7174a7a30811a7478213c7fccfa547603/photo/MenZ-TONE_length_change.png">

<br clear="all">

#### プログラムを書き込み、曲を確認する ####

---

**この作業はArduinoや、ゆびトーンの故障につながる可能性があります**
<br>
**自己の責任において作業を行ってください**

---

1. ArduinoとゆびトーンからAVRを外す

   ソケットとAVRの間にマイナスドライバを差し込み、少し持ち上げます。<br>
   これをAVR両端で交互に行い、徐々にAVRを持ち上げソケットから外します。<br>
   ソケットからAVRを外すときは、足を曲げないように注意しながら外してください。<br>

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove1.JPG" width="20%" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove2.JPG" width="20%" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove3.JPG" width="20%">

2. ゆびトーンから外したAVRをArudinoに取り付ける

   逆差しをしないよう、ICソケットとAVRの切り欠きを確認して差し込みます。<br>
   外すときのことを考え、最後まで刺さずに軽く浮かせておくと良いでしょう。<br>

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_attachavr.JPG" width="30%">

3. プログラムを書き込む

   いつものようにプログラムを書き込みましょう。

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_writecode.JPG" width="30%">

4. 動作確認

   Arduinoに取り付けたAVRをゆびトーンに戻して動作を確認します。
   このときも、ICソケットの切り欠きとAVRの切り欠きの位置を十分注意して差し込みましょう。

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_run.JPG" width="30%">

<br clear="all">

### 参考URL ###

* [Wikipedia - Music Macro Language](https://ja.wikipedia.org/wiki/Music_Macro_Language)
   - とりあえず基礎的なことを学びましょう
* [マビノギ MML作曲ツール 3ML EDITOR 2 Webpage](http://3ml.jp/)
   - かなりお世話になっているツールですこれがないと始まりません

### どうやって連絡すれば良い？ ###

* http://www.the-menz.com/contact.html
