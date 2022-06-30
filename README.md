# LuaJava #

[![Build Status](https://github.com/gudzpoz/luajava/actions/workflows/build-natives.yml/badge.svg)](https://github.com/gudzpoz/luajava/actions/workflows/build-natives.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
![Codecov](https://img.shields.io/codecov/c/github/gudzpoz/luajava?label=Coverage)
[![Sonatype Nexus (Snapshots)](https://img.shields.io/nexus/s/party.iroiro.luajava/luajava?server=https%3A%2F%2Fs01.oss.sonatype.org&label=Nexus&color=pink)](https://s01.oss.sonatype.org/content/repositories/snapshots/party/iroiro/luajava/)
[![Maven Central](https://img.shields.io/maven-central/v/party.iroiro.luajava/luajava?color=blue&label=Maven%20Central)](https://mvnrepository.com/search?q=party.iroiro.luajava)

[![Build Status](https://github.com/gudzpoz/luajava/actions/workflows/docs.yml/badge.svg)](https://github.com/gudzpoz/luajava/actions/workflows/docs.yml)
[![Document Version](https://img.shields.io/github/package-json/v/gudzpoz/luajava?filename=docs%2Fpackage.json&label=Documentation)](https://gudzpoz.github.io/luajava/)

* [About](#about)
* [Platforms and Versions](#platforms-and-versions)
  * [Artifacts](#artifacts)
* [Module `java`](#java-module)
  * [Example](#examples)
* [Credits](#credits)
* [License](#license)

## About ##

This is yet another fork of [the original LuaJava](https://github.com/jasonsantos/luajava).

> LuaJava is a scripting tool for Java. The goal of this tool is to allow scripts written in Lua to manipulate components developed in Java. LuaJava allows Java components to be accessed from Lua using the same syntax that is used for accessing Lua's native objects, without any need for declarations or any kind of preprocessing.
>
> LuaJava also allows Java to implement an interface using Lua. This way any interface can be implemented in Lua and passed as parameter to any method, and when called, the equivalent function will be called in Lua, and it's result passed back to Java.
>
> LuaJava is available under the same license as Lua 5.1, that is, it can be used at no cost for both academic and commercial purposes.

Documentation is available at [LuaJava](https://gudzpoz.github.io/luajava/) along with Javadoc.

## Platforms and Versions ##

Lua 5.1, Lua 5.2, Lua 5.3, Lua 5.4 and LuaJIT are supported.

Compiled natives are available for most common platforms. Check out [LuaJava Platforms](https://gudzpoz.github.io/luajava/#platforms) for a platform matrix.

### Artifacts

To include LuaJava into your project, you need to include two artifacts, one for the Java bindings, the other for the compiled native binaries.

Different artifacts are provided for different Lua versions and different platforms. Check out [Getting Started](https://gudzpoz.github.io/luajava/getting-started.html) for an overview. Or you may also search in the [Maven Central](https://mvnrepository.com/search?q=party.iroiro.luajava).

## Java module ##

[The `java` module](https://gudzpoz.github.io/luajava/api.html#java-module) provides these functions:

- `import`: Import classes from Java
- `new`: Construct a Java object
- `proxy`: Create a Java object, calls to whose method will be proxied to Lua functions
- `luaify`: Convert Java values to Lua values
- `method`: Provide an alternative way to call Java methods

### Examples

Here is a simple example on how to correctly initialize new Lua instance.
This example will push `message` variable to Lua with value `Hello World from Lua`, then prints it using the Java `println`.

```java
public static void main(String[] args) {
    try (Lua L = new Lua51()) {
        L.push("Hello World from LuaJava");
        L.setglobal("message");
        L.run("java.import('java.lang.System').out:println(message)");
    }
}
```

### More ###

Check out [AWT Example](https://gudzpoz.github.io/luajava/examples/awt.html) for a more complex example.

You may also have a look at [our tests](./example/src/test/resources).

## Credits ##

 * [LuaJava](https://github.com/jasonsantos/luajava)
 * [LibGDX](https://github.com/libgdx/libgdx)
 * [jnigen](https://github.com/libgdx/gdx-jnigen)
 * [Nonlua](https://github.com/deathbeam/jua)

## License ##

Code under [./example](./example) is licensed under [GNU General Public License
Version 3](https://www.gnu.org/licenses/gpl-3.0.txt).

Other parts are licensed under [the MIT license](https://opensource.org/licenses/MIT).
