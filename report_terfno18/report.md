# 18 計算科学 レポート
<div style="text-align:center;">3-C-19 Takahito Sueda</div>

## 可視化ツールについて有名な3製品程度を調べてその特徴を報告せよ。
### AR.js
three.jsの進化版。
ブラウザ上でARを有効にするライブラリで、webGLを応用している。
記述が非常に簡単という特徴がある。
サンプル[^1]
[^1]:参考：https://qiita.com/shizuma/items/8616bbe3ebe8ab0b6ca1
```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>A-frame & AR.js sample</title>
  </head>
  <body style="margin:0px; overflow:hidden;">
    <!-- A-Frame-->
    <script src="https://aframe.io/releases/0.6.1/aframe.min.js"></script>
    <!-- AR.js-->
    <script src="https://jeromeetienne.github.io/AR.js/aframe/build/aframe-ar.js"></script>
    <a-scene embedded arjs="debugUIEnabled:false;">
      <a-marker preset="hiro">
        <a-box position="0 0.5 0" wireframe="true"></a-box>
      </a-marker>
      <a-entity camera></a-entity>
    </a-scene>
  </body>
</html>
```
実行すると`hiro`というマーカー上に白いフレームのサイコロが表示できる。

### Grimoire.js
webGLのライブラリ。
UnityなどのツールやCGの制作、webGLのコーディングなどに使用できる。
またJavaScriptだけでなくAltJSのTypeScriptにも対応している。
OSSなのも特徴の1つ。
サンプル[^2]
[^2]:参考：https://grimoire.gl/
```html
<goml>
  <scene>
    <camera></camera>
    <mesh texture="logo.png" geometry="cube">
      <mesh.components>
        <Rotate speed="1,1,1" />
      </mesh.components>
    </mesh>
  </scene>
</goml>
```
```javascript
gr(function() {
  var mesh = gr('#simple .canvas')('mesh')
  $('#simple .red').on('click', function () {
    mesh.setAttribute('color', 'red')
  })
  $('#simple .blue').on('click', function () {
    mesh.setAttribute('color', 'blue')
  })
  mesh.on('mouseenter', function () {
    mesh.setAttribute('scale', '2.0')
    $("#simple .bigger").addClass("bold-label");
    $("#simple .smaller").removeClass("bold-label");
  })
  mesh.on('mouseleave', function () {
    mesh.setAttribute('scale', '1.0')
    $("#simple .smaller").addClass("bold-label");
    $("#simple .bigger").removeClass("bold-label");
  })
})
```
実行すると白いサイコロがくるくる回る。

### Unity
Unityは物理エンジンであるが、webGLを制作することも可能である。
webGLで動くゲームを作ることも可能で、応用することでさまざまな可視化ツールを実装できる。

サンプルとして球の落下を物理演算する可視化ツールを作成した。[^3]
[^3]:参考：https://qiita.com/kenta71/items/c32760e1cc2ba01e8f9a

URL:https://terfno.github.io/unity_webgl_practice/
リポジトリ:https://github.com/Terfno/unity_webgl_practice

## 参考
